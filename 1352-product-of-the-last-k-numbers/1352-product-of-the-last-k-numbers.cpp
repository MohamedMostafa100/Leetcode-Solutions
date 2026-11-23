class ProductOfNumbers {
private:
    vector<int> nums;
    int length;
    int lastZero;
public:
    ProductOfNumbers() {
        nums.push_back(1);
        length = 0;
        lastZero = -1;
    }
    
    void add(int num) {
        if(num > 0)
        {
            nums.push_back(nums[nums.size() - 1] * num);
        }
        else
        {
            lastZero = length;
            nums.push_back(1);
        }
        length++;
    }
    
    int getProduct(int k) {
        return length - k <= lastZero ? 0 : nums[nums.size() - 1] / nums[nums.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */