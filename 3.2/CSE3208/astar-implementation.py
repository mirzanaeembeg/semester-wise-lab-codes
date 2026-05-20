from queue import PriorityQueue

# Function to read the graph from a file (Undirected Graph)
def read_graph_from_file():
    graph = {}
    
    with open("Input_graph", "r") as file:
        for line in file:
            from_node, to_node = line.strip().split()
            
            # Add edge in both directions (undirected)
            if from_node not in graph:
                graph[from_node] = []
            if to_node not in graph:
                graph[to_node] = []
                
            graph[from_node].append(to_node)
            graph[to_node].append(from_node)  # Reverse edge for undirected graph

    return graph

# Heuristic function (h-values for each node)
def get_h_value(node):
    h_values = {
        'A': 10,
        'B': 8,
        'C': 5,
        'D': 3,
        'E': 0
    }
    return h_values.get(node, 0)

# A* Search Algorithm
def astar(graph, start, goal):
    open_list = PriorityQueue()
    open_list.put((0 + get_h_value(start), 0, start, [start]))  # (f(n), g(n), node, path)
    
    visited = set()
    
    while not open_list.empty():
        f, g, current, path = open_list.get()
        
        # If goal is reached, return path
        if current == goal:
            return path, f
        
        # Skip if node already visited
        if current in visited:
            continue
        
        visited.add(current)
        
        # Process neighbors
        if current in graph:
            for neighbor in graph[current]:
                if neighbor not in visited:
                    new_g = g + 1  # Assuming cost of 1
                    new_f = new_g + get_h_value(neighbor)
                    new_path = path + [neighbor]
                    open_list.put((new_f, new_g, neighbor, new_path))
    
    return None, None

# Main function to run A* search
def main():
    graph = read_graph_from_file()
    
    start = input("Enter start node: ")
    goal = input("Enter goal node: ")
    
    path, final_cost = astar(graph, start, goal)
    
    if path:
        print("\nPath found:")
        for node in path:
            g = path.index(node)  # g(n) = distance from start
            h = get_h_value(node)  # h(n) = heuristic value
            f = g + h  # f(n) = g(n) + h(n)
            print(f"Node: {node}, f(n) = {f} [g(n) = {g}, h(n) = {h}]")
    else:
        print("\nNo path found!")

if __name__ == "__main__":
    main()
