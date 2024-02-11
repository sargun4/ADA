
# 4. Pareto Optimal Pairs Algorithm:

# The Pareto optimal pairs algorithm can be implemented using a simple scan through the collection of ordered pairs. The idea is to iterate through the pairs and keep track of the Pareto optimal pairs encountered.
 
def pareto_optimal_pairs(ordered_pairs):
    pareto_optimal = []

    for u, v in ordered_pairs:
        is_pareto_optimal = all((u >= x and v >= y) for x, y in ordered_pairs if (x, y) != (u, v))
        if is_pareto_optimal:
            pareto_optimal.append((u, v))

    return pareto_optimal
 
ordered_pairs = [(1, 4), (2, 3), (3, 2), (4, 1)]
result = pareto_optimal_pairs(ordered_pairs)
print(f"Pareto optimal pairs: {result}")

# Running Time Analysis:

# The algorithm performs a linear scan through the collection of ordered pairs.
# For each pair, it checks dominance against all other pairs, which results in a quadratic complexity.
# The overall running time is O(n^2), where n is the number of ordered pairs.
# Justification:

# The algorithm checks dominance for each pair individually.
# The condition (u >= x and v >= y) for x, y in ordered_pairs if (x, y) != (u, v) ensures that the current pair is not dominating itself.
# The algorithm correctly identifies Pareto optimal pairs based on the definition.