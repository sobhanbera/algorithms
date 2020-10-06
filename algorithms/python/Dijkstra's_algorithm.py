global visited_and_distance

# Function to find out which of the unvisited node 
# needs to be visited next
def to_be_visited(number_of_vertices,visited_and_distance):
  
  v = -10
  # Choosing the vertex with the minimum distance
  for index in range(number_of_vertices):
    if visited_and_distance[index][0] == 0 \
      and (v < 0 or visited_and_distance[index][1] <= \
      visited_and_distance[v][1]):
        v = index
  return v


#Main Function
def Dijkstra(vert,edg):

  import sys

  # Creating the graph as an adjacency matrix
  vertices = vert
  edges =  edg

  number_of_vertices = len(vertices[0])

  # The first element of the lists inside visited_and_distance 
  # denotes if the vertex has been visited.
  # The second element of the lists inside the visited_and_distance 
  # denotes the distance from the source.
  visited_and_distance = [[0, 0]]
  for i in range(number_of_vertices-1):
    visited_and_distance.append([0, sys.maxsize])

  for vertex in range(number_of_vertices):
    # Finding the next vertex to be visited.
    to_visit = to_be_visited(number_of_vertices,visited_and_distance)
    for neighbor_index in range(number_of_vertices):
      # Calculating the new distance for all unvisited neighbours
      # of the chosen vertex.
      if vertices[to_visit][neighbor_index] == 1 and \
       visited_and_distance[neighbor_index][0] == 0:
        new_distance = visited_and_distance[to_visit][1] \
        + edges[to_visit][neighbor_index]
        # Updating the distance of the neighbor if its current distance
        # is greater than the distance that has just been calculated
        if visited_and_distance[neighbor_index][1] > new_distance:
          visited_and_distance[neighbor_index][1] = new_distance
    # Visiting the vertex found earlier
    visited_and_distance[to_visit][0] = 1

  i = 0 

  # Printing out the shortest distance from the source to each vertex       
  for distance in visited_and_distance:
    print("The shortest distance of ",chr(ord('a') + i),\
    " from the source vertex a is:",distance[1])
    i = i + 1

print("\nFor graph[(a,b),(a,c),(b,c),(c,d)] where a is the source vertex:\n")
Dijkstra(vert = [[0, 1, 1, 0],
                [0, 0, 1, 0],
                [0, 0, 0, 1],
                [0, 0, 0, 0]],

        edg = [[0, 3, 4, 0],
              [0, 0, 0.5, 0],
              [0, 0, 0, 1],
              [0, 0, 0, 0]])    


print("\nFor graph[(a,b),(b,c),(b,d),(c,d),(d,e),(c,e)] where a is the source vertex:\n")
Dijkstra(vert = [[0,1,0,0,0],
                [0,0,1,1,0],
                [0,0,0,1,1],
                [0,0,0,0,1],
                [0,0,0,0,0]],

        edg = [[0,4,0,0,0],
              [0,0,2,3,0],
              [0,0,0,1.5,0.5],
              [0,0,0,0,3],
              [0,0,0,0,0]])  
