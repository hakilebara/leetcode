int numWaterBottles(int numBottles, int numExchange) {
  int numEmptyBottles = 0;
  int numDrunkBottles = 0;
  while (numBottles) {
    numDrunkBottles += numBottles;
    numEmptyBottles += numBottles;
    numBottles = numEmptyBottles / numExchange;
    numEmptyBottles = numEmptyBottles % numExchange;
  }
  return numDrunkBottles;
}
