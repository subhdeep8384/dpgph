import java.util.*;

class Edge {
    int v;
    int weight;

    Edge(int v, int weight) {
        this.v = v;
        this.weight = weight;
    }
}

public class dijj {

    public static void dijkstra(int V, int src, ArrayList<ArrayList<Edge>> g) {

        // {distance, node}
        PriorityQueue<int[]> pq =
                new PriorityQueue<>((a, b) -> a[0] - b[0]);

        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[src] = 0;
        pq.offer(new int[]{0, src});

        while (!pq.isEmpty()) {

            int[] curr = pq.poll();

            int currDistance = curr[0];
            int node = curr[1];

            if (currDistance > dist[node]) {
                continue;
            }

            for (Edge neighbour : g.get(node)) {

                int adjNode = neighbour.v;
                int weight = neighbour.weight;

                // edge relaxation
                if (dist[node] + weight < dist[adjNode]) {

                    dist[adjNode] = dist[node] + weight;

                    pq.offer(
                        new int[]{
                            dist[adjNode],
                            adjNode
                        }
                    );
                }
            }
        }

        for (int i = 0; i < V; i++) {
            System.out.println(i + " -> " + dist[i]);
        }
    }

    public static void main(String[] args) {

        int V = 6;

        ArrayList<ArrayList<Edge>> g = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            g.add(new ArrayList<>());
        }

        g.get(0).add(new Edge(1, 2));
        g.get(0).add(new Edge(2, 4));

        g.get(1).add(new Edge(3, 7));
        g.get(1).add(new Edge(2, 1));

        g.get(2).add(new Edge(4, 3));

        g.get(3).add(new Edge(5, 1));

        g.get(4).add(new Edge(3, 2));
        g.get(4).add(new Edge(5, 5));

        dijkstra(V, 0, g);
    }
} 