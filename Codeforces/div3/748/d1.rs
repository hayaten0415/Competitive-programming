fn main() {
  let mut t:usize = input();
  while t > 0 {
    solve();
    t -= 1;
  }
}

fn solve() {
  let n:usize= input();
  let mut num:Vec<i64> = input_vec();
  num.sort();
  let mut ans:u64 = 0;
  for i in 1..n {
    ans = gcd(ans, (num[i]- num[i-1]) as u64);
  }
  if ans == 0 {
    println!("-1");
    return;
  }
  println!("{}", ans);
}


fn gcd(a:u64, b:u64)-> u64 {
  let smaller = a.min(b);
  let bigger = a.max(b);
  if smaller == 0 {return bigger;}
  let mut surplus = bigger % smaller;
  if surplus == 0 {return smaller;}
  surplus = gcd(smaller, surplus);
  surplus
}

#[allow(dead_code)]
pub fn input<T: std::str::FromStr>() -> T {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).ok();
  input.trim().parse().ok().unwrap()
}

#[allow(dead_code)]
pub fn input_t2<T: std::str::FromStr, U: std::str::FromStr>() -> (T, U) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).ok();
  let s = input.trim().split_whitespace().collect::<Vec<&str>>();
  (s[0].parse().ok().unwrap(), s[1].parse().ok().unwrap())
}

#[allow(dead_code)]
pub fn input_vec<T: std::str::FromStr>() -> Vec<T> {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).ok();
  input.trim().split_whitespace().map(|e| e.parse().ok().unwrap()).collect()
}