class MinStack {
public:
   stack<int>st;
   stack<int>gt;
    MinStack() {
        
    }
    
    void push(int val) {
      st.push(val);

    if(gt.empty() || val <= gt.top()) {
        gt.push(val);
    }
    }
    
    void pop() {
        if(st.top()==gt.top()){
            st.pop();
            gt.pop();
        }else{
            st.pop();
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return gt.top();
        
    }
};
