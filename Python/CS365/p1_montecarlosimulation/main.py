import math
import random
import pandas


class MonteCarloSimulation:
    def __init__(self, no_of_samples: int, no_of_tries: int):
        self.no_of_samples = no_of_samples
        self.no_of_tries = no_of_tries
    
    def read_dataset(self, file_path: str, col_name: str):
        self.data_frame = pandas.read_csv(file_path)[col_name]
    
    def start(self):
        self.predicted_avg: float = 0
        sum: float = 0
        
        for i in range(self.no_of_tries):
            random_index = math.floor(self.no_of_samples * random.random())
            sum += self.data_frame[random_index]
        
        self.predicted_avg = sum / self.no_of_tries
        print(f"Predicted average: {self.predicted_avg}")
    
    def calculate_accuracy(self):
        real_avg: float = sum(self.data_frame) / self.no_of_samples
        print(f"Real average: {real_avg}")
        print(f"Accuracy: {100 - abs(real_avg-self.predicted_avg)/real_avg}")


    

if __name__ == '__main__':
    simulation: MonteCarloSimulation = MonteCarloSimulation(500, 100)
    simulation.read_dataset("height.csv", "Height")
    simulation.start()
    simulation.calculate_accuracy()
