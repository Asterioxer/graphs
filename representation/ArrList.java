package representation;

//import java.lang.reflect.Array;
import java.util.ArrayList;

public class ArrList {
    ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    public static void main(String[] args) {
        int n = 3, m = 3;

        ArrList graph = new ArrList(); // Create a constructor of class

        for (int i = 0; i <= n; i++) {
            graph.adj.add(new ArrayList<Integer>());
        }

        // edge 1---2
        graph.adj.get(1).add(2);
        graph.adj.get(2).add(1);

        // edge 2---3
        graph.adj.get(2).add(3);
        graph.adj.get(3).add(2);

        // edge 1---3
        graph.adj.get(1).add(3);
        graph.adj.get(3).add(1);

        // edge u---v
        // int u = ...; int v = ...;
        // graph.adj.get(u).add(v); // edge u---v
        // graph.adj.get(v).add(u); // edge v---u

        //for directed graph
        // int u = ...; int v = ...;
        // graph.adj.get(u).add(v);

        // Example for adding edge u---v
        // int u = ...; int v = ...;
        // graph.adj.get(u).add(v); // edge u---v
        // graph.adj.get(v).add(u); // edge v---u

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph.adj.get(i).size(); j++) {
                System.out.print(graph.adj.get(i).get(j) + " ");
            }
          System.out.println();
        }
    }
}
