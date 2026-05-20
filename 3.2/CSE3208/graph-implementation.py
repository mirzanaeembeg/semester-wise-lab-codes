# Program 1: Graph Implementation with File I/O
# ID: 20210204033

class Graph:
    def __init__(self):
        self.graph = {}
    
    # Add edge between u and v with weight (undirected)
    def add_edge(self, u, v, weight=1):
        # Ensure u is in graph
        if u not in self.graph:
            self.graph[u] = []
        # Ensure v is in graph (in case it's an isolated node)
        if v not in self.graph:
            self.graph[v] = []
        
        # Add edge from u to v
        self.graph[u].append((v, weight))
        # Add edge from v to u (making it undirected)
        self.graph[v].append((u, weight))

    # Add edge between u and v with weight (directed)
    # def add_edge(self, u, v, weight=1):
    #     if u not in self.graph:
    #         self.graph[u] = []
    #     self.graph[u].append((v, weight))


def write_graph_to_file():
    graph = Graph()
    filename = "Input_graph"
    
    with open(filename, "w") as f:
        num_vertices = int(input("Enter number of vertices: "))
        num_edges = int(input("Enter number of edges: "))
        
        print(f"{num_vertices} {num_edges}", file=f)
        
        print("\nEnter edges in format: source destination weight h_value")
        for i in range(num_edges):
            u, v, w, h = input(f"Edge {i+1}: ").split()
            graph.add_edge(u, v, int(w))
            print(f"{u} {v} {w} {h}", file=f)
    
    return filename

def read_and_print_edges(filename):
    print("\nReading edges from file:")
    with open(filename, "r") as f:
        num_vertices, num_edges = map(int, f.readline().split())
        print(f"Number of vertices: {num_vertices}")
        print(f"Number of edges: {num_edges}")
        print("\nEdges:")
        
        for line in f:
            u, v, w, h = line.split()
            print(f"({u}, {v}) with weight: {w}, h_value: {h}")

if __name__ == "__main__":
    filename = write_graph_to_file()
    read_and_print_edges(filename)