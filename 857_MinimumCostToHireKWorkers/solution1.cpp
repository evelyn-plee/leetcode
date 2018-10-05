using namespace std;

class Solution{
public:
    struct Worker{
        int quality, wage;
        double ratio;
        Worker(int q, int w){
            quality = q;
            wage = w;
            ratio = (double)quality/(double)wage;
        }
    };
    
    class Compare{
        bool operator()(const Worker& a, const Worker& b){
            return a.ratio < b.ratio;
        }
    };

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K){
        int n = quality.size();
        vector<Worker> workers;
        for(int i = 0; i < n; ++i){
            workers.push_back(Worker(quality[i], wage[i]));
        }
        
        sort(workers.begin(), workers.end(), Compare());
        
        priority_queue<int> pq;
        int totalQuality = 0;
        double res = 1e9;
        for(auto worker: workers){
            pq.push(worker.quality);
            totalQuality += worker.quality;
            
            if(pq.size() > K){
                totalQuality -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == K){
                res = min(res, totalQuality*worker.ratio);
            }
        }
        return res;
    }

};
