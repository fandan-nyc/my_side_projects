class Complex {
    
    public:
        Complex(double, double);
        Complex(double);
        Complex();
        
        double real() const ;
        double img() const;
        
        void real(double); 
        void img(double);
        
        void print() const;
        
        Complex& operator+= (const Complex&);
        Complex& operator-=(const Complex&);
        
    private:
        double realNum, imgNum;
};
