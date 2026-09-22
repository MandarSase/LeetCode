class Solution {
public:

    struct Node {
        int prod;
        long long pref[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(Node left, Node right) {

        Node res;

        res.prod = (left.prod * 1LL * right.prod) % k;

        for (int r = 0; r < k; r++) {
            res.pref[r] += left.pref[r];
        }

        for (int r = 0; r < k; r++) {

            int newRem = (left.prod * 1LL * r) % k;

            res.pref[newRem] += right.pref[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {

            int rem = nums[l] % k;

            seg[node].prod = rem;
            seg[node].pref[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, 2 * node, l, mid);
        build(nums, 2 * node + 1, mid + 1, r);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int index, int value) {

        if (l == r) {

            int rem = value % k;

            seg[node] = Node();

            seg[node].prod = rem;
            seg[node].pref[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(2 * node, l, mid, index, value);
        }
        else {
            update(2 * node + 1, mid + 1, r, index, value);
        }

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        if (qr < l || r < ql) {
            return Node();
        }

        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        }

        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->n = nums.size();
        this->k = k;

        seg.assign(4 * n + 5, Node());

        build(nums, 1, 0, n - 1);

        vector<int> result;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            result.push_back(res.pref[x]);
        }

        return result;
    }
};