from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional


class DataStream(ABC):
    
    def __init__(self, stream_id):
        self.stream_id = stream_id
    
    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        ...

    def filter_data(self, data_batch: List[Any], criteria: Optional[str]
        = None) -> List[Any]:
        ...

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        ...


class SensorStream(DataStream):
    
    def __init__(self, stream_id):
        super().__init__(stream_id)
        self.data_type = "Environmental Data"
    
    def process_batch(self, data_batch: List[Any]) -> str:
        
        if not data_batch:
            return "No data is provided"
        else:
            temp = 0
            analysis_total = 0
            temp_total = 0
            for ele in data_batch:
                if isinstance(ele, dict):
                    analysis_total += len(ele)
                    temp += ele.get('temp', 0)
                    temp_total += 1
                else:
                    return "The data is not well structured (dict)"
            return f"Sensor analysis: {analysis_total} readings processed, avg temp: {temp / temp_total}°C"

class TransactionStream(DataStream):
    
    def __init__(self, stream_id):
        super().__init__(stream_id)
        self.data_type = "Financial Data"
    
    def process_batch(self, data_batch: List[Any]) -> str:
        
        if not data_batch:
            return "No data is provided"
        else:
            net_flow = 0
            for ele in data_batch:
                if isinstance(ele, dict):
                    operation = ele['operation']
                    amount = ele['amount']
                    net_flow += amount if operation == "buy" else -amount
                else:
                    return "The data is not well structured (dict)"
            sign = "+" if net_flow > 0 else ""
            return f"Transaction analysis: {len(data_batch)} operations, net flow: {sign}{net_flow} units"


class EventStream(DataStream):
    
    def __init__(self, stream_id):
        super().__init__(stream_id)
        self.data_type = "System Events"

    def process_batch(self, data_batch: List[Any]) -> str:
        
        if not data_batch:
            return "No data is provided"
        else:
            errors = 0
            analysis_total = 0
            temp_total = 0
            for ele in data_batch:
                analysis_total += len(ele)
                if isinstance(ele, list):
                    for event in ele:
                        errors += 1 if event.lower() == "error" else 0
                else:
                    return "The data is not well structured (dict)"
            return f"Event analysis: {analysis_total} events, {errors} error detected"


class StreamProcessor:
    ...

if __name__ == "__main__":

    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n")

    print("Initializing Sensor Stream...")
    sensor_01 = SensorStream("SENSOR_001")
    print(f"Stream ID: {sensor_01.stream_id}, Type: {sensor_01.data_type}")
    print("Processing sensor batch: [temp:22.5, humidity:65, pressure:1013]")
    sensor_batch = [{"temp": 22.5, "humidity": 65, "pressure": 1013}]
    print(sensor_01.process_batch(sensor_batch))

    print("\nInitializing Transaction Stream...")
    trans_01 = TransactionStream("TRANS_001")
    print(f"Stream ID: {trans_01.stream_id}, Type: {trans_01.data_type}")
    print("Processing transaction batch: [buy:100, sell:150, buy:75]")
    trans_batch = [
        {"operation": "buy", "amount": 100},
        {"operation": "sell", "amount": 150},
        {"operation": "buy", "amount": 75}
        ]
    print(trans_01.process_batch(trans_batch))

    print("\nInitializing Event Stream...")
    event_01 = EventStream("EVENT_001")
    print(f"Stream ID: {event_01.stream_id}, Type: {event_01.data_type}")
    print("Processing event batch: [login, error, logout]")
    event_batch = [["login", "error", "logout"]]
    print(event_01.process_batch(event_batch))

    print("=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...\n")