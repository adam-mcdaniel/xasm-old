



fn() {
    // new function returns an empty table
    // name table `self`
    new ! self =

    fn(self, value, sign) {
        value self.value =
        sign self.sign =

        self // return self at end of constructor
    } self.constructor =


    fn(self, value) {
        value self.value =
    } self.set_value =

    
    fn(self, value) {
        1 self.value + self.value =
    } self.increment =

    self
} Number =




// cons function will call the `constructor` attribute of the value returned when calling `Number`
false 5 Number!.constructor! num =

num.value println !
num.increment!
num.increment!
num.value println !
