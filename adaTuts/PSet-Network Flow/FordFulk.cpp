
initialize flow to 0

// initializing the flow of the graph to 0 at the start
for each edge (u, v) in G:
    flow(u, v) = 0
 
// augmenting path
while there is a path, p, from s -> t in residual graph:
    residual_capacity(p) = min(residual_capacity(u, v) : for(u, v) in p)
    flow = flow + residual_capacity(p)
    
    // updating the graph after using the augmenting path for flow
    for each edge (u, v) in p:
        if(u, v) is a forward edge:
            flow(u, v) = flow(u, v) + residual_capacity(p) 
        else:
            flow(u, v) = flow(u, v) - residual_capacity(p)

return flow