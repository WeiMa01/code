
class Solution {
public:
    string multiply(string num1, string num2) {
        string result, tmp_result;
        int n1 = num1.size()-1, n2 = num2.size()-1;
        int up = 0, tmp1, tmp2, time=0;
        int shift =0;

        for(int i = n1; i>=0; i--){
            tmp1 = num1[i] - '0';
            tmp_result.clear();
            up = 0;
            for (int j = n2;j>=0;j--){
                
                tmp2 = num2[j] - '0';
                //结果加尾数
                tmp_result.push_back((tmp1 * tmp2 + up) %10  + '0');
                up =  (tmp1 * tmp2 + up) /10;
                // cout << "tmp result: " << tmp_result << "  up: "  << up <<  endl;
            }
            if (up != 0){
                // cout << "up " << up << endl;
                tmp_result.push_back(up + '0');
            }
            // reverse(tmp_result.begin(),tmp_result.end());
            cout << " tmp result: " << tmp_result << endl;
            string ttt;
            for(int i = 0;i < shift; i++){
                ttt.push_back(result[i]);
            }

            int length;
            if(tmp_result.size() + 1 + shift > result.size()){
                length = tmp_result.size();
            }else{
                length = (result.size() - 1 -shift);
            }
            up = 0;
            for (int i = 0; i < length; i++)
            {
                if(i < tmp_result.size() ){
                    tmp1 = tmp_result[i] - '0';
                }else tmp1 = 0;

                if( i + shift< result.size()){
                    tmp2 = result[i + shift] - '0';
                }else tmp2 = 0;
                cout << " tmp1: " << tmp1 << "  tmp2:" << tmp2 << " up:" << up<< endl;
                ttt.push_back( (tmp1 + tmp2 + up) % 10 + '0');
                up =  (tmp1 + tmp2 + up) / 10;
            }
            if (up != 0){
                ttt.push_back( up + '0');
            }
            cout << "result: " << result << endl;
            result = ttt;
            cout <<  "ttt:" << ttt << endl;
            
            time++;
            shift++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
