use proconio::input;

fn main() {
  input! {
    n : usize,
    a: [i64;n]
  }
  let mut ans = std::i64::MAX;
  for i in 0..2 {
    let mut dp = vec![vec![std::i64::MAX;2]; n];
    if i == 0 {dp[0][0] = 0};
    if i == 1 {dp[0][1] = a[n-1]};
    for i in 0..n-1 {
      dp[i+1][0] = dp[i+1][0].min(dp[i][1]);
      dp[i+1][1] = dp[i+1][1].min(
        dp[i][1].min(dp[i][0])
        + a[i]
      );
    }
    if i == 1 {
      dp[n-1][1] = dp[n-1][0].min(dp[n-1][1]);
    }
    ans = ans.min(dp[n-1][1]);
  }

  println!("{}", ans);
}
