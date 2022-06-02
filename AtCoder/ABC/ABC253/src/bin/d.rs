use proconio::input;
fn main() {
  input! {
    n :i64,
    a:i64,
    b:i64,
  }
  let mut ans = (1 + n) * n / 2;
  ans -= a * (n / a + 1) * (n / a) / 2;
  ans -= b * (n / b + 1) * (n / b) / 2;
  let d = lcm(a, b);
  ans += d * (n / d + 1) * (n / d) / 2;
  println!("{}", ans);
}


fn gcd(a:i64, b:i64)-> i64 {
  let smaller = a.min(b);
  let bigger = a.max(b);
  if smaller == 0 {return bigger;}
  let mut surplus = bigger % smaller;
  if surplus == 0 {return smaller;}
  surplus = gcd(smaller, surplus);
  surplus
}

fn lcm(a:i64, b:i64)-> i64 {
  a / gcd(a, b) * b
}