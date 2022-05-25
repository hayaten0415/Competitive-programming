fn main() {
  let mut t:usize = input();
  while t > 0 {
    solve();
    t -= 1;
  }
}

fn solve() {
  let f:(i64, usize) = input_t2();
  let (n, k) = f;
  let mut place:Vec<i64> = input_vec();
  place.sort_by(|x, y| (-x).partial_cmp(&(-y)).unwrap());
  let mut cat_place = 0;
  let mut ans = 0;
  for i in 0..k {
    if place[i] <= cat_place {break;}
    ans += 1;
    cat_place += n - place[i];
  }
  println!("{}", ans);
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