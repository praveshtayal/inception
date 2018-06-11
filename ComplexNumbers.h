class ComplexNumbers
{
  public:
    ComplexNumbers(int r=0, int i=0);
    void plus(const ComplexNumbers &c);
    void multiply(const ComplexNumbers &c);
    void print() const;
  private:
  int re,im;
};
