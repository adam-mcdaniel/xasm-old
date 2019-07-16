


{
    // new function returns an empty table
    // name table `self`
    new ! self =

    (self, value, sign) {
        value self.value =
        sign self.sign =

        self // return self at end of constructor
    } self.constructor =


    (self, value) {
        value self.value =
    } self.set_value =

    self
} Number =




// cons function will call the `constructor` attribute of the value returned when calling `Number`
false 5 Number cons ! num =

num.value print !


