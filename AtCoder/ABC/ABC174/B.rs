use proconio::input;

fn main() {
    input! {
        n: usize,
        d: i64,
        mut a: [(i64, i64); n],
    }
    let mut ans = 0;
    for (i, j) in a.iter().enumerate() {
        if j.0 * j.0 + j.1 * j.1 <= d * d {
            ans += 1;
        }
    }
    println!("{}", ans);
}
