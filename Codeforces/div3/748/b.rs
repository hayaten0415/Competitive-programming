fn main() {
  let mut t:usize = input();
  while t > 0 {
    solve();
    t -= 1;
  }
}

fn solve() {
  let a:u64 = input();
  let mut ans = usize::MAX;
  let mut zero:Vec<usize> = Vec::new();
  let mut two:Vec<usize> = Vec::new();
  let mut five:Vec<usize> = Vec::new();
  let mut seven:Vec<usize> = Vec::new();
  let a_str: String = a.to_string();
  let a_char: Vec<char> = a_str.chars().collect();
  let n = a_char.len();
  for i in 0..a_char.len() {
    if a_char[i] == '0' {
      zero.push(i);
    }
    if a_char[i] == '2' {
      two.push(i);
    }
    if a_char[i] == '5' {
      five.push(i);
    }
    if a_char[i] == '7' {
      seven.push(i);
    }
  }
  for i in 0..zero.len() {
    let left = zero[i];
    for j in i+1..zero.len() {
      let right = zero[j];
      let mut tmp = n - 1 - right;
      if left + 1 != right {
        tmp += (right - left) - 1;
      }
      ans = ans.min(tmp);
    }
  }
  for i in 0..two.len() {
    let left = two[i];
    for j in 0..five.len() {
      let right = five[j];
      if left > right {continue;}
      let mut tmp = n - 1 - right;
      if left + 1 != right {
        tmp += (right - left) - 1;
      }
      ans = ans.min(tmp);
    }
  }
  for i in 0..five.len() {
    let left = five[i];
    for j in 0..zero.len() {
      let right = zero[j];
      if left > right {continue;}
      let mut tmp = n - 1 - right;
      if left + 1 != right {
        tmp += (right - left) - 1;
      }
      ans = ans.min(tmp);
    }
  }
  for i in 0..seven.len() {
    let left = seven[i];
    for j in 0..five.len() {
      let right = five[j];
      if left > right {continue;}
      let mut tmp = n - 1 - right;
      if left + 1 != right {
        tmp += (right - left) - 1;
      }
      ans = ans.min(tmp);
    }
  }
  println!("{}", ans);
}


#[allow(dead_code)]
pub fn input<T: std::str::FromStr>() -> T {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).ok();
  input.trim().parse().ok().unwrap()
}