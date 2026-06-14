import java.util.* ;
class Edgee {
    public  int v ;
    public int weight ;
    
    Edgee(int v , int weight){
        this.v = v; 
        this.weight = weight ;
    }
}

class Pair{
    public int node ;
    public int distance ;
    Pair(int node , int dist ){
        this.node = node ;
        this.distance = dist ;
    }
}

public class d {
    public static void dijkstra(int V , int src , ArrayList<ArrayList<Edgee>> g){
        
        PriorityQueue<Pair>pq = new PriorityQueue<>((a,b) -> a.distance - b.distance ) ;
        Integer [] dist = new Integer[V] ;
        Arrays.fill(dist , Integer.MAX_VALUE) ;
        dist[src] = 0  ;
        pq.offer(new Pair(src , 0)) ;

        while(!pq.isEmpty()){
            Pair p = pq.poll() ;
            int currDistance = p.distance ;
            int node  = p.node ;

            if(currDistance > dist[node])continue ;

            for(Edgee neigh : g.get(node)){
                int adjNode = neigh.v ;
                int weight = neigh.weight ;

                if(dist[node] + weight < dist[adjNode]){
                    dist[adjNode] = dist[node] + weight ;
                    pq.offer(
                        new Pair(adjNode , dist[adjNode]) 
                    ) ;
                }
            }
        }

        for(int i = 0 ; i < V ; i++ ){
             System.out.println(i + " -> " + dist[i]);
        }
    }
    public static void main(String [] args ){
        int V = 6 ;
        ArrayList<ArrayList<Edgee>> g = new ArrayList<>() ;
        for(int i = 0 ; i < V ; i++ ){
            g.add(new ArrayList<>() );
        }

        g.get(0).add(new Edgee(1, 2));
        g.get(0).add(new Edgee(2, 4));

        g.get(1).add(new Edgee(3, 7));
        g.get(1).add(new Edgee(2, 1));

        g.get(2).add(new Edgee(4, 3));

        g.get(3).add(new Edgee(5, 1));

        g.get(4).add(new Edgee(3, 2));
        g.get(4).add(new Edgee(5, 5));

        dijkstra(V, 0, g);
    }
}
