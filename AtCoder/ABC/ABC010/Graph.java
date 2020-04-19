import java.util.*;
import java.io.*;

class Graph {
  private int V;
  private LinkedList<Integer> adj[];
  // Constructor 
  Graph(int v) { 
    V = v; 
    adj = new LinkedList[v]; 
    for(int i=0; i<v; ++i) 
      adj[i] = new LinkedList(); 
  }

  void addEdge(int v, int w) {
    adj[v].add(w);
    adj[w].add(v);
  }

  void print() {
    adj.getFirst();
  }

  
  public static void main(String[] args) {
    Graph g1 = new Graph(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    System.out.println(g1.get);
  }
}