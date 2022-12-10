#include "algo.hpp"
#include <algorithm>

Algo::Algo(
    vector<vector<int>> g) {
  // assign the graph
  // null check
  if(g == NULL) {
    // decide what to do?
    graph = g;
  }
  graph = g;
}

// need to write this out
<<<<<<< Updated upstream
void Algo::DijSolve(Vertex v){
    // pseudocode instructions
    for each (Vertex v : G) {
      d[v] = +inf
      p[v] = NULL
      d[s] = 0
      PriorityQueue Q // min distance, defined by d[v]
      Q.buildHeap(G.vertices())
      Graph T // "labeled set"
      repeat n times:
      Vertex u = Q.removeMin()
      T.add(u)
      foreach (Vertex v : neighbors of u not in T):
        if cost(u, v) + d[u] < d[v] {
          d[v] = cost(u, v) + d[u]
                  p[v] = u
        }
    }
=======
void Algo::DijSolve(Vertex s){
  // use func to find index location of s
  int s_loc = find_vertex_ind(s);
  map<Vertex, double> time_diff = map<Vertex, double>();
  vector<bool> sptSet = vector<bool>();
  
  // start of the algorithim by pushing back "infinite" (largest double) values to dist vector
  // this ensures that all actual values will be considered minimums when compared to these
  // start of the algorithim by pushing back false values to dist vector
  // basically meaning that you are setting all verticies to NOT be part of the path at the start
  for (int i = 0; i < all_verticies.size(); i++){
      time_diff.insert(std::pair<Vertex, double>(all_vertices.at(i), DOUBLE_MAX));
      sptSet.push_back(false);
  }

  // self to self distance MUST be 0
  dist.at(s_loc) = 0.0;

  // find shortest path for all vertices
  // size is all but self
  for (int count = 0; count < all_verticies.size() - 1; count++) {
      int min_dist_vertex_ind = minDistance(dist, sptSet);

      // Mark the picked vertex as processed
      sptSet[min_dist_vertex_ind] = true;
      for (int v = 0; v < all_verticies.size(); v++){
          if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
            dist[v] = dist[u] + graph[u][v];
          }
      }

  // print the constructed distance array
}    
    // // pseudocode instructions
    // for (Vertex v : all_vertices) {
    //   d[v] = DOUBLE_MAX;
    //   p[v] = NULL;
    //   d[s] = 0
    //   PriorityQueue Q // min distance, defined by d[v]
    //   Q.buildHeap(G.vertices())
    //   Graph T // "labeled set"
    //   repeat n times:
    //   Vertex u = Q.removeMin()
    //   T.add(u)
    //   foreach (Vertex v : neighbors of u not in T):
    //     if cost(u, v) + d[u] < d[v] {
    //       d[v] = cost(u, v) + d[u]
    //               p[v] = u
    //     }
    // }
>>>>>>> Stashed changes
}



// presuming bus data is smth like this, so subject to change

// @brief sets up the data for all vertices and all edges vectors -- used in the graph initialization 
// and other methods 
// void Algo::translate_data(vector<Bus> buses) {
//   for (Bus b : buses) {
//     // vertex vector?
//     vector<string> stops = b.stops;
//     vector<double> times = b.times;
//     /// how is the data like time being saved? route name? etc

//     for (size_t index = 0; index < stops.size() - 1; index++) {
//       // vertex 1 and 2
//       Vertex v1(stops[index]);
//       v1.addRoute(b.route);
//       Vertex v2(stops[index + 1]);
//       v2.addRoute(b.route);
//       // don't wanna readd vertices
//       if (find(all_vertices.begin(), all_vertices.end(), v1) == all_vertices.end()) {
//         all_vertices.push_back(v1);
//       }
//       if (find(all_vertices.begin(), all_vertices.end(), v2) == all_vertices.end()) {
//         all_vertices.push_back(v2);
//       }

//       Edge edge(times[index], b.route, v1, v2);
//       all_edges.push_back(edge);
//     }
//   }
// }

/// @brief basically for each start vertex, we get a map of its end vertex and the edges 
// that exist between these two points

void Algo::build_graph() {
  for (Edge e : all_edges) {
    graph[e.start][e.end].push_back(e);
  }
}

bool Algo::DFS_connected_on_route(string route_, string start_, string end_) {
  // found end
  if (start_ == end_) return true;

  map<Vertex, bool> visited;
  Vertex v_start = find_vertex(start_);
  Vertex v_end = find_vertex(end_);
  Edge edge = find_edge(route_, start_, end_);

  // can't move forward on route
  if (edge == Edge()) return false;

  visited[v_start] = true;
  // note, unsure about iterator notation
  for (auto it = graph.begin(); it != graph.end(); ++it) {
    if (!visited(it -> first)) {
      DFS_connected_on_route(route_, *it.stop, end_);
    }
  }
}

// better way to translate stop name to vertex?
Vertex find_vertex(string stop_){
  for (Vertex v : all_vertices) {
    if (v.stop == stop_)
      return v;
  }
  return Vertex();
}

Edge find_Edge(string route_, Vertex start_, Vertex end_){
  for (Edge e : graph[start_][end_]) {
    if (e.route == route_)
      return e;
  }
  return Edge();
}
<<<<<<< Updated upstream
=======

int find_vertex_ind(Vertex v){
  //user iterator to locate element
  auto location = find(all_verticies.begin(), all_verticies.end(), v);
  // If element doesn't exist return -1
  if (location == all_verticies.end()) {
    return -1;
  }
  return location - all_verticies.begin();
}

int minDistance(map<Vertex, double> time_diff, vector<bool> sptSet){
  // start by setting the minimum value to the largest possible double value 
  // this ensure all vals accessed after are actual minimums
  double min_val = DOUBLE_MAX;
  int min_index = -1;

  // 
  for (int i = 0; i < all_verticies.size(); i++){
    // now check if the point isn't already in the shortest path, and check to make sure it is less than the minimum val
    if (sptSet.at(i) == false && time_diff[all_verticies.at(i)] <= min_val){
      // update min val
      min_val = time_diff[all_verticies.at(i)];
      // update min_index to be index of min
      min_index = i;
    }
  }
  return min_index;
}

>>>>>>> Stashed changes
// vector<vector<vector<Edge>>> graph;

// void build_graph(vector<Vertex> all_vertices, vector<Edge> all_edges){
// // pseudocode instructions

// // resize the graph vector to 
// for(int i = 0; i < all_verticies.size(); i++) {
//   vector<vector<Edge>> outer_vec = vector<vector<Edge>>();
//   for(int j = 0; j < all_verticies.size(); j++) {
//     vector<Edge> inner_vec = vector<Edge>();
//     inner_vec.push_back(Edge());
//     outer_vec.push_back(inner_vec);
//     }
//   graph.push_back(outer_vec);
// }

// // for each edge, find the vertex and set their distance
//   for(int i = 0; i < all_edges.size(); i++) {
//     Vertex start_ = all_edges[i].start;
//     Vertex destination_ = all_edges[i].end;

//     int start_index = find_index_in_vector(all_verticies, start_);
//     int destination_index = find_index_in_vector(all_verticies, destination_);

//     graph[start_index][destination_index].push_back(all_edges[i]);
//     graph[destination_index][start_index].push_back(all_edges[i]);
//   }
// }

// int find_index_in_vector(vector<Vertex> all_verticies, Vertex v) {
//   //user iterator to locate element
//   auto location = find(v.begin(), v.end(), K);
//   // If element doesn't exist return -1
//   if (location == v.end()) {
//     return -1;
//   }
//   return location - v.begin();
// }


bool Algo::RouteConnectionMain(string route, string origin, string destination) {
     if (origin == destination) {
        cout << "Found destination" << endl;
        return true;
    }

    map<Vertex, bool> visited;
    for (Vertex v : vertices)
         visited[v] = false;

    Vertex start = findVertex(origin);
    Vertex end = findVertex(destination);
    return RouteConnection(route, start, end, visited);
 }



bool Algo::RouteConnection(string route, Vertex origin, Vertex destination,  map<Vertex, bool>& visited) {
    // If the origin and destination are the same, they are obviously
    // connected.
    if (origin.stop == destination.stop) {
        cout << "Found destination" << endl;
        return true;
    }

     // Find out if there is an edge in between origin and destination.
    Edge edge = findEdge(route, start, end);
    // If there isn't, we can't move forward on route.
    if (edge == Edge()) {
        return false;
        cout << "Can't move foward" << endl;
    }

    visited[start] = true;
    // For each entry in graph:
    for (auto it = graph[start].begin(); it != graph[start].end(); ++it) {
        // If the origin vertex hasn't been visited,
        cout << "enter graph iteration" << endl;
       // bool has_route = false;
       // string stop = "";
        for (Edge e : it -> second) { 
            if (visited.find(it->first) != visited.end() && !visited[it->first] /&& e.route == route/) {
            cout << "not visited" << endl;
           // has_route = true;
           // stop = it -> first.stop;
            RouteConnection(route, it->first, destination, visited);
            }
        }
     /*   if (has_route && stop != destination) {
            return false;
            cout << "Can't move foward and not at stop" << endl;
        }*/
    }

    return true; // 
}
 
Edge Algo::findEdge(string route, Vertex origin, Vertex destination) {
if (graph.find(origin) != graph.end() && graph[origin].find(destionation) != graph[origin].end()) {
    for (Edge edge : graph[origin][destination]) {
        if (edge.route == route) {
            // cout << "Edge was found." << endl;
            return edge;
        }
    }
}
    // cout << "Edge was not found." << endl;
    return Edge();
}`