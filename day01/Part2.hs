main = do
    contents <- readFile "input"
    let list = map readInt . words $ contents
    print $ head [x*y*z | x <- list, y <- list, z <- list, x + y + z == 2020]

readInt :: String -> Int
readInt = read
