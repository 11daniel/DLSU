import heapq

class UniformCostSearch:
    def __init__(self, graph):
        self.graph = graph

    def search(self, start, goal):
        frontier = []
        heapq.heappush(frontier, (0, start))

        visit_count = {start: 1}
        max_frontier_size = 0
        cost_so_far = {start: 0}
        came_from = {start: None}
        visited_order = []

        while frontier:
            max_frontier_size = max(max_frontier_size, len(frontier))
            current_cost, current_node = heapq.heappop(frontier)
            visited_order.append(current_node)

            if current_node == goal:
                path = []
                while current_node is not None:
                    path.append(current_node)
                    current_node = came_from[current_node]
                return visited_order, cost_so_far[goal], path[::-1], len(visited_order), max_frontier_size, visit_count

            for neighbor, cost in self.graph[current_node].items():
                new_cost = current_cost + cost
                neighbor_cost = cost_so_far.get(neighbor, float('inf'))

                if new_cost < neighbor_cost:
                    cost_so_far[neighbor] = new_cost
                    heapq.heappush(frontier, (new_cost, neighbor))
                    came_from[neighbor] = current_node
                    visit_count[neighbor] = visit_count.get(neighbor, 0) + 1

        return visited_order, float('inf'), [], len(visited_order), max_frontier_size, visit_count

