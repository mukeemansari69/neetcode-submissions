class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        int n = h.size();

        vector<int> nsi(n);
        vector<int> psi(n);

        stack<int> st;

        // NSI
        st.push(n - 1);

        nsi[n - 1] = n;

        for(int i = n - 2; i >= 0; i--) {

            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();

            if(st.empty())
                nsi[i] = n;
            else
                nsi[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // PSI
        st.push(0);

        psi[0] = -1;

        for(int i = 1; i < n; i++) {

            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();

            if(st.empty())
                psi[i] = -1;
            else
                psi[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            int width = nsi[i] - psi[i] - 1;
            int area = width * h[i];

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};