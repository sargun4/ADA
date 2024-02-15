// File Replication and Access Cost Optimization:
// Consider a scenario where we want to replicate a file across a collection of n servers, labeled S1, S2, …, Sn. Each server has an associated placement cost denoted by ci (where ci > 0). When a user requests the file from a server Si, and no copy of the file is present at Si, the servers Si+1, Si+2, Si+3, … are searched in order until a copy of the file is found (say at server Sj, where j > i). This incurs an access cost of j - i. We need to place copies of the file at the servers to minimize the sum of placement and access costs.
// To find the configuration of minimum total cost, we can use dynamic programming. Let’s build a table T[], where T[i] stores the minimum sum of placement and access cost assuming we have servers Si, Si+1, …, Sn and we place a copy at Si. The recurrence relation for T[i] is:
// T[i]=ci​+k=i+1minn​((k−i)(k−i−1)+T[k])
// We start with T[n] = c_n. To compute T[i], we consider placing the next copy at T[k] (where k > i). The access cost incurred is (k - i)(k - i - 1). By minimizing this cost and adding the placement cost c_i, we update T[i]. Finally, the optimal configuration can be obtained by backtracking through the table.
// This algorithm runs in polynomial time and efficiently finds the configuration that minimizes the total cost of file replication and access1
// Summary: Use dynamic programming to minimize the sum of placement and access costs when replicating files across servers1

// https://www.cse.iitd.ac.in/~amitk/SemI-2017/tut6.pdf
