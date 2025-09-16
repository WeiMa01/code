struct Node{
    int val;
    Node * next;
    Node(){}
    Node(int v){
        val = v;
        next = nullptr;
    }
    Node(int v, Node* p){
        val = v;
        next = p;
    }
};

class Solution {
public:
    int GCD(int a, int b){
        //最大公约数
        int min_num =  a < b ? a :b;
        for (int i = min_num; i > 0; i--)
        {
            if(a % i == 0 && b%i == 0){
                return i;
            }
        }
        return 1;
    }
    int LCM(int a, int b){
        //  最小公倍数
        int max_num = a > b ? a: b;
        for (int i = max_num; i <= a * b; i++)
        {
            if(i % a == 0 && i %b ==0){
                return i;
            }
        }
        return a*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        //有很多删除操作，尝试使用链表
        int n = nums.size();
        if (n == 1) return nums;
        Node * head = nullptr, *p = nullptr;
        vector<int> result;
        //构建链表
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << endl;
            Node *new_node = new Node(nums[i]);
            if (i == 0) {
                head = new_node;
                p = head;
            }else{
                p->next = new_node;
                p = p-> next;
            }
        }
        p = head;
        Node * next_p = p-> next;
        int num1, num2, num3;
        while(next_p != nullptr){
            num1 = p->val;
            num2 = next_p->val;
            if( GCD(num1, num2) != 1){
                //有最大公约数
                num3 = LCM(num1, num2);
                // 删除 next_p 这个节点
                p->val = num3;
                p->next = next_p->next;
                delete next_p;
                next_p = p->next;
            }else{
                p = p->next;
                next_p = next_p-> next;
            }
        }
        p = head;
        while(p != nullptr){
            result.push_back(p -> val);
            p = p-> next;
        }
        return result; 
    }
};
