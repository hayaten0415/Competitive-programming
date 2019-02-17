n = gets.to_s
loop{
  if n[0] == n[1] && n[1] == n[2]
    puts n; exit
  end
  n = n.to_i
  n += 1
  n = n.to_s
}