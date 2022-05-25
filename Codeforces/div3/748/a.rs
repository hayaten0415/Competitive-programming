fn main() {
  let mut t:usize = input();
  while t > 0 {
    solve();
    t -= 1;
  }
}

fn solve() {
  let f:(i64, i64, i64) = input_t3();
  let (a, b, c) = f;
  println!("{} {} {}", 0.max(b.max(c) -a + 1), 0.max(a.max(c) -b + 1), 0.max(a.max(b) -c + 1));
}


#[allow(dead_code)]
pub fn input<T: std::str::FromStr>() -> T {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).ok();
  input.trim().parse().ok().unwrap()
}

#[allow(dead_code)]
pub fn input_t3<T: std::str::FromStr, U: std::str::FromStr, X: std::str::FromStr>() -> (T, U, X) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).ok();
  let s = input.trim().split_whitespace().collect::<Vec<&str>>();
  (s[0].parse().ok().unwrap(), s[1].parse().ok().unwrap(), s[2].parse().ok().unwrap())
}