use proconio::input;

fn main() {
    input! {
        a: usize,
        b: usize,
        x: usize,
    }
    let  f = |s:usize| {s.to_string().len()};
    let mut right = 1000000001;
    let mut left = 0;
    while (right - left) > 1 {
        let mid = (right + left) / 2;
        if a * mid + b * f(mid) <= x {
            left = mid;
        }else {
            right = mid;
        }
    }
    println!("{}", left)
}
