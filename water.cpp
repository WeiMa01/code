
class Solution {
public:
    int trap(vector<int>& height) {
        //双指针，left 表示左边界，right 表示右边界，中间有凹进去的就可以存储雨水
        // left记录最高的位置,如果有高于当前left的柱子，则left++;如果有低于left的柱子，则left不懂。后面有高于left的柱子，则计算中间的雨水。
        int left =0, right = 1, num=0;
        int length = height.size();
        cout << "length: " << length << endl;
        while(left < length && right < length){
            cout <<" left: " << left <<"  right: "<< right << endl;
            
            if(right - left == 1 ){
                if(height[right] >= height[left]){
                    left ++;
                    right++;
                }else{
                    right++;
                }
                continue;
            }
            // 找大于的点，中间可以存雨水
            while (right < length)
            {
                // cout <<" left: " << left <<"  right: "<< right << endl;
                if(height[right] < height[left]){
                    right ++;
                }else{
                    cout <<"计算雨水的 left: " << left <<"  right: "<< right << endl;
                    //height[right] >= height[left]
                    //计算雨水量
                    int i = left +1;
                    while(i < right){
                        num = num + (height[left] - height[i]); 
                        i++;
                    }
                    left = right;
                    right ++;
                    break;
                }   
            }  
            if (right == length){
                // left++;
                // right = left + 1;
                cout <<" right == length 计算雨水的 left: " << left <<"  right: "<< right << endl;
                if (height[left] >= height[right-1]){
                    cout <<"计算雨水的 left: " << left <<"  right: "<< right << endl;
                    //height[right] >= height[left]
                    //计算雨水量
                    int i = left +1;
                    while(i < right){
                        num = num + (height[right-1] - height[i]); 
                        i++;
                    }
                    left ++;
                    right = left + 1;
                }
            } 
        }
        return num;
    }
};
