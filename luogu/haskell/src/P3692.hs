module P3692 where
    data TestType = TypeA | TypeB deriving (Show, Eq)
    data Id = Id Int (Maybe TestType) deriving (Show)
    data Answer = AnsA | AnsB | AnsC | AnsD deriving (Show, Eq)

    type CorrectType = Bool
    type Score = Double
    data JudgeResult = JudgeResult Id CorrectType Score deriving (Show)

    answerPair 'A' = AnsA
    answerPair 'B' = AnsB
    answerPair 'C' = AnsC
    answerPair 'D' = AnsD

    -- Correct Answers -> BinaryID -> TestType -> [Input Answer] -> Result
    judge :: String -> String -> String -> [String] -> JudgeResult
    judge ans id t input = JudgeResult parseId isTypeCorrect judge'
        where
            parseAnswers = map answerPair ans
            parseId = Id (binaryString2dec id) parseType
            parseType 
                | t == "10" = Just TypeA
                | t == "01" = Just TypeB
                | otherwise = Nothing
            isTypeCorrect = parseType == if last id == '0' then Just TypeA else Just TypeB
            parseInput input
                | input == "1000" = Just AnsA
                | input == "0100" = Just AnsB
                | input == "0010" = Just AnsC
                | input == "0001" = Just AnsD
                | otherwise = Nothing
            judge' = 100 / (fromIntegral $ length ans) * (fromIntegral $ length $ filter (==True) $ map (\(ans, input) -> Just ans == parseInput input) $ zip parseAnswers input)

    binaryString2dec :: String -> Int
    binaryString2dec = binary2dec . map (\x -> read [x]) . reverse
        where
            binary2dec :: [Int] -> Int
            binary2dec [] = 0
            binary2dec (x : xs) = x + 2 * binary2dec xs