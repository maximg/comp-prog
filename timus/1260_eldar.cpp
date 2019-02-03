int g(int n)
{
    //H = highest number
    //L = H - 1
    //D = dot, means any other number
    enum {
        LHD = 0,
        HLD,
        LH,
        HL,
        DH,
        TOTAL
    };

    vi v(TOTAL);

    v[DH] = 1;

    for(int i = 2; i <= n; i++)
    {
        vi t(TOTAL);

        t[HLD] = v[LHD];
        t[LHD] = v[HLD];

        t[LH]  = v[LH];
        t[HL]  = v[LH];

        t[HLD] += v[HL];
        t[DH]  =  v[HL];

        t[LH]  += v[DH];

        v = t;
    }

    int ans = 0;
    for(auto x : v) ans += x;

    return ans;
}
