/************************************************************************/
/*  @author tapiream
    @version 0.1
	@date July 6th 2012
	@Singleton
*/
/************************************************************************/

#ifndef __EAM_SINGLETON_H__
#define __EAM_SINGLETON_H__

namespace eam
{
template <typename T> 
class Singleton  
{  
	static T* _instance;  
public:  
	static T* instance();
	static void release();
protected:  
	Singleton(){};
	virtual ~Singleton(){}; 
	Singleton<T>& operator=(const Singleton<T>& rhs);
	Singleton(const Singleton<T>& rhs);
};  


template <class T> T* Singleton<T>::_instance = 0;



template <class T> T* Singleton<T>::instance()  
{  
	if(!_instance)  
		_instance = new T();  
	return _instance;  
}

template <class T> void Singleton<T>::release()  
{  
	if( _instance )  
	{  
		delete _instance;  
		_instance = 0;  
	}  
}

}
#endif //__EAM_SINGLETON_H__