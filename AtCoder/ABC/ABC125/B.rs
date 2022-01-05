use proconio::input;


fn main() {
    input! {
        n : usize,
        v: [i64; n],
        c: [i64; n],
    }
    let mut ans = 0;
    for bit in 0..(1 <<n) {
        let mut cost = 0;
        let mut value = 0;
        for i in 0..n {
            if (1 << i) & bit != 0 {
                cost += c[i];
                value += v[i];
            }
        }
        ans = ans.max(value-cost);
    }
    println!("{}", ans)
}