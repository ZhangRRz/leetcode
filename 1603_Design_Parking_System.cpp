class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        cartype_left[0] = big;
        cartype_left[1] = medium;
        cartype_left[2] = small;
    }
    
    bool addCar(int carType) {
        if(cartype_left[carType-1]){
            cartype_left[carType-1]--;
            return true;
        }
        return false;
    }
private:
    int cartype_left[3] = {0};
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
