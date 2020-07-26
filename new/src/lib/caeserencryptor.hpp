/**
 * @file encription.h
 * @author milos94 (an.milos94@gmail.com)
 * @brief Defines concepts, classes and utiliy functions for encryption/decryption
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "common.hpp"

#include <type_traits>

namespace kerberos::encryption {

/**
 * @brief utility trait to check whether the value_type of the contaner (C) and the type of the other value(V) are addable
 * 
 * @tparam C type of the container
 * @tparam V type of the value
 */
template< typename C, typename V >
inline constexpr bool is_addable_b = std::is_nothrow_convertible_v< decltype( std::declval< typename C::value_type >() + std::declval< V >() ),
																	typename C::value_type >;

/**
 * @brief utility trait to check whether the value_type of the contaner (C) and the type of the other value (V) are subtractable
 * 
 * @tparam C - type of the container
 * @tparam V - type of the value
 */
template< typename C, typename V >
inline constexpr bool is_subtractable_b = std::is_nothrow_convertible_v< decltype( std::declval< typename C::value_type >() - std::declval< V >() ),
																	     typename C::value_type >;

/**
 * @brief helper trait that is the combination of is_addable_b and is_subtractable_b
 * 
 * @tparam C - type of the ontainer
 * @tparam V - type of the value
 */
template< typename C, typename V>
inline constexpr bool is_addabe_and_subtractable_b = is_addable_b<C,V> && is_subtractable_b<C,V>;


/**
 * @brief Encryptor that uses Ceaser chyper to encrypt/decrypt text.
 *        Ceaser shift is a type of sustitute chiper in which each letter in the plaintext
 *        is replaced by a letter some fixed number of positions down the alphabet.
 * 		  This extended to addition and sustraction of any types that support these operators.
 * @note  Overlowing is not handled, so if you are using custom types you need to take care of this.
 * 
 */
template< typename T = unsigned int>
struct CaeserEncryptor
{

	/**
      * @brief Construct a new Caeser Encryptor object
      * 
      * @param value - value to be used for the shift
      */
	explicit constexpr CaeserEncryptor( T const &value ) noexcept : shift_{ value }
	{
	}

	/**
	* @brief Construct a new CaeserEncryptor object
    * @note  Default constructed CeaserEncrytopr will have shift 0, so encryptring/decrypting data will do nothing.
    *        Before use it is recommended to use set_shift so that the CaeserEncrytopr works properly.
	* 
	*/
	constexpr CaeserEncryptor() noexcept = default;

	/**
     * @brief Default copy constructor
     * 
     */
	constexpr CaeserEncryptor( CaeserEncryptor const & ) noexcept = default;

	/**
     * @brief Default move constructor
     * 
     */
	constexpr CaeserEncryptor( CaeserEncryptor && ) noexcept = default;

	/**
     * @brief Default copy operator=
     * 
     * @return CaeserEncryptor& 
     */
	constexpr CaeserEncryptor &operator=( CaeserEncryptor const & ) noexcept = default;

	/**
     * @brief Default move operator=
     * 
     * @return CaeserEncryptor& 
     */
	constexpr CaeserEncryptor &operator=( CaeserEncryptor && ) noexcept = default;

	/**
	 * @brief Destroy the Caeser Encryptor object
	 * 
	 */
	~CaeserEncryptor() noexcept = default;

	/**
	 * @brief Set the value of the shift. Make sure that the value of shift is the same when encryptiong and decrypting.
	 * 
	 * @param shift - value of the shift to be used when ecrypting/decryptiong
	 */
	void set_shift(T const & shift)
	{
		shift_=shift;
	}
	
	/**
	 * @brief Get the current value of the shift
	 * 
	 * @return T - value of the shift
	 */
	constexpr T get_shift() const
	{
		return shift_;
	}

	/**
     * @brief Encrypt the data thats passed as argument.
     *        This method is noexcept if the operator+ for the value_type of the container and T is noexcept and container C is noexcept copy constructible
     * @note  This method will make a copy of passed in data and work on that
     *        If you don't need to keep the original data you can use encrypt_inplace
     * 
     * @tparam C - type of the container that will be used 
     * @param buffer - data that needs to be encrypted
     * @return C - container containing ecrypted data
     */
	template< typename C >
	constexpr std::enable_if_t< is_addabe_and_subtractable_b< C, T >, C > encrypt( C const &buffer ) const
	  noexcept( noexcept( std::declval< typename C::value_type >() + std::declval< T >() ) && std::is_nothrow_copy_constructible_v< C > )
	{
		C return_value{ buffer };
		for ( auto &val : return_value ) {
			val = val + shift_;
		}

		return return_value;
	}

	/**
      * @brief Decrypt the data thats passed as argument
      *        This method is noexcept if the operator- for the value_type of the container and T is noexcept and container C is noexcept copy constructible
      * @note  This method will make a copy of passed in data and work on that
      *        If you don't need to keep the original data you can use encrypt_inplace
      * 
      * @tparam C - type of the container that will be used
      * @param buffer - data that needs to be decrypted
      * @return C - container containing decrypted data
      */
	template< typename C >
	constexpr std::enable_if_t< is_addabe_and_subtractable_b< C, T >, C > decrypt( C const &buffer ) const
	  noexcept( noexcept( std::declval< typename C::value_type >() - std::declval< T >() ) && std::is_nothrow_copy_constructible_v< C > )
	{
		C return_value{ buffer };
		for ( auto &val : return_value ) {
			val = val - shift_;
		}

		return return_value;
	}

	/**
      * @brief Encrypt the data thats passed as argument
      *        This method is noexcept if the operator+ for the value_type of the container and T is noexcept
      * @note  This method does the encryption inplace
      *        If you don't want your original data to be changed use the ecnrypt method
      * 
      * @tparam C - type of the container that will be used
      * @param buffer - data that needs to be encrypted
      */
	template< typename C >
	constexpr std::enable_if_t< is_addabe_and_subtractable_b< C, T >, void > encrypt_inplace( C &buffer ) const
	  noexcept( noexcept(std::declval< typename C::value_type >() + std::declval< T >()) )
	{
		for ( auto &val : buffer ) {
			val = val + shift_;
		}
	}

	/**
      * @brief Decrypt the data thats passed as argument
      *        This method is noexcept if the operator- for the value_type of the container and T is noexcept
      * @note  This method does the decryption inplace
      *        If you don't want your original data to be changed use the decrypt method
      * 
      * @tparam C - type of the container that will be used
      * @param buffer - data that needs to be decrypted
      */
	template< typename C >
	constexpr std::enable_if_t< is_addabe_and_subtractable_b< C, T >, void > decrypt_inplace( C &buffer ) const
	  noexcept( noexcept(std::declval< typename C::value_type >() - std::declval< T >()) )
	{
		for ( auto &val : buffer ) {
			val = val - shift_;
		}
	}

  private:
	T shift_;
};

}// namespace kerberos::encryption