#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job
{
      string id;
      int deadline;
      int profit;
};

bool compare(Job a, Job b)
{
      return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs, int n)
{
      sort(jobs.begin(), jobs.end(), compare);

      int maxDeadline = 0;

      for (int i = 0; i < n; i++)
      {
            if (jobs[i].deadline > maxDeadline)
            {
                  maxDeadline = jobs[i].deadline;
            }
      }

      vector<string> slot(maxDeadline + 1, " ");
      vector<bool> filled(maxDeadline + 1, false);

      int totalProfit = 0;
      for (int i = 0; i < n; i++)
      {
            for (int j = jobs[i].deadline; j > 0; j--)
            {
                  if (!filled[j])
                  {
                        slot[j] = jobs[i].id;
                        filled[j] = true;

                        totalProfit += jobs[i].profit;
                        break;
                  }
            }
      }

      cout << "Job sequencing:";
      for (int i = 1; i <= maxDeadline; i++)
      {
            if (filled[i])
            {
                  cout << slot[i] << " ";
            }
      }

      cout << "Total profit:" << totalProfit;
}

int main()
{
      int n;
      cout << "Enter total number of jobs:";
      cin >> n;
      vector<Job> jobs(n);

      cout << "Enter a id , deadline and profit\n";
      for (int i = 0; i < n; i++)
      {
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
      }

      jobSequencing(jobs, n);
      return 0;
}