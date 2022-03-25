use proconio::input;

fn main() {
    input! {
        n : usize,
        a: [(f32, f32); n]
    }
    let mut t :f32 = 0.0;
    for i in 0..n {
        t += a[i].0 / a[i].1;
    }
    let mut ans :f32 = 0.0;
    t /= 2.0;
    for i in 0..n {
        ans += a[i].0.min(t * a[i].1);
        t -= t.min(a[i].0 / a[i].1)
    }
    println!("{:.6}", ans);
}
