#ifndef BIGINTEGER_FOR_EUCLID

#define BIGINTEGER_FOR_EUCLID

class BigInteger{
public:
	int *data;
  BigInteger();
  BigInteger(const int&);
  BigInteger(const std::string&);
  BigInteger(const BigInteger&);
  ~BigInteger();

  bool operator<(const BigInteger&) const;
  BigInteger operator%(const BigInteger&) const;
  BigInteger& operator=(const BigInteger&);
  bool iszero();

  friend std::ostream& operator<<(std::ostream&, const BigInteger&);

};


#endif
