class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>res;
        int level=-1;
        int count=0;
        while(label>count)
        {
            level++;
            count+=pow(2,level);
        }
        int parent;
        do{
            res.push_back(label);
            if(label%2==0)
            {
                parent=label/2;
            }
            else
            {
                parent=(label-1)/2;
            }
            level--;
            int level_element_count=pow(2,level);
            int last_element_of_level=2*level_element_count-1;
            int diff=last_element_of_level-parent;
            label=level_element_count+diff;
        }while(label>0);
        reverse(res.begin(),res.end());
        return res;
    }
};
