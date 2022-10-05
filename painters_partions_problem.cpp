// Painters Partions Problem Solved on Code studio Platform 
class Solution {
public:
int minDays(vector<int>& bloomDay, int m, int k) {

    int flowerCounter = 0;
    int bouquetCounter = 0;
    int totalFlower = m*k;

    if(bloomDay.size() < totalFlower)
        return -1;

    int start = *min_element(bloomDay.begin(),bloomDay.end());
    int end = *max_element(bloomDay.begin(),bloomDay.end());
    int mid = start + (end - start)/2;

    while(start < end){
        for(int i = 0; i < bloomDay.size();i++){
            if(mid >= bloomDay[i])
                flowerCounter++;
            else{
                if(flowerCounter > k && (flowerCounter % k != 0)){
                bouquetCounter += floor((double)flowerCounter/k);
                flowerCounter = 0;
              }
              else if(flowerCounter % k != 0)
                    flowerCounter = 0;
              }
        }
          bouquetCounter += floor((double)flowerCounter/k);

            if( bouquetCounter < m )
                start = mid + 1;
            else 
                end = mid ;

            mid = start + (end - start)/2;

            bouquetCounter = 0;
            flowerCounter = 0;
        }


    return end ;
}
};