use proconio::input;

fn main() {
    input! {
        n :usize,
        x: u64,
        a:  [[u64]; n]
    }
    let ans = dfs(0, n, 1, x, &a);
    println!("{}", ans);
}

fn dfs(i: usize, n: usize, prd: u64, x: u64, a: &Vec<Vec<u64>>) ->u64 {
    if i == n {
        return {
            if prd == x {1}
            else {0}
        }
    }
    let mut ans = 0;
    for val in a[i].iter() {
        if prd  > x / val {continue;}
        ans += dfs(i + 1, n, prd * val, x, a);
    }
    ans
}