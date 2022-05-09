use proconio::input;

fn main() {
    input! {
        mut s: String,
    }
    let mut d: Vec<char> = s.chars().collect();
    let mut min = d.clone();
    let mut max = d.clone();
    for _ in 0..d.len() {
        d.rotate_left(1);
        min = min.min(d.clone());
        max = max.max(d.clone());
    }
    let ans1: String = min.iter().collect();
    let ans2: String = max.iter().collect();
    println!("{}\n{}",ans1, ans2);
}