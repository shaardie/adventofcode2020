main = do
    contents <- readFile "input"
    let list = map readInt . words $ contents
    print $ head [x*y | x <- list, y <- list, x + y == 2020]

readInt :: String -> Int
readInt = read
