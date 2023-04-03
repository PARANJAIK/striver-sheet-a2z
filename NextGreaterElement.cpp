// Q) Next Greater Element -> https://www.youtube.com/watch?v=Du881K7Jtk8&t=0s

// Ans) USING STACK : 

// i) 1st variant : If it is a circular array thing, means,if we dont find a greater element on the right, then we will see from the 0th index till that index also.

vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }


// ii) 2nd variant : If circular array is not the scene and here if u dont find any greater element in its right, its greater element is -1.

vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = n - 1; i >= 0; i--) {     // n - 1 is the only change
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }