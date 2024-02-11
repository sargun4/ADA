# 2. Suppose you are given two sets of distinct points, one set {p1, . . . , pn} on line y = 0
# and the other set {q1, q2, . . . , qn} on line y = 1. Create a set of n line segments
# by connecting each point pi with qi

# . Describe a divide and conquer algorithm to
# determine the number of these line segments that intersect in O(n log n)-time.



# Divide and Conquer Algorithm for Counting Intersecting Line Segments:

# Assuming the sets of points are already sorted by their x-coordinates, you can use a divide-and-conquer algorithm to
#  determine the number of intersecting line segments.
 
def count_intersecting_segments(points_y0, points_y1):
    if len(points_y0) <= 1:
        return 0

    mid = len(points_y0) // 2
    mid_point = points_y0[mid]

    left_y0 = [point for point in points_y0 if point[0] <= mid_point[0]]
    right_y0 = [point for point in points_y0 if point[0] > mid_point[0]]

    left_y1 = [point for point in points_y1 if point[0] <= mid_point[0]]
    right_y1 = [point for point in points_y1 if point[0] > mid_point[0]]

    count = count_intersecting_segments(left_y0, left_y1) + count_intersecting_segments(right_y0, right_y1)

    for point_y1 in points_y1:
        if point_y1[0] < mid_point[0]:
            count += len(left_y0)
        elif point_y1[0] > mid_point[0]:
            count += len(right_y0)

    return count
 
points_y0 = [(1, 0), (3, 0), (5, 0)]
points_y1 = [(2, 1), (4, 1), (6, 1)]
result = count_intersecting_segments(points_y0, points_y1)
print(f"Number of intersecting line segments: {result}")