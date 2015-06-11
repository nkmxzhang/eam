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
	static T* ms_instance;  
public:  
	static T* Get();
	static void Free();
protected:  
	Singleton(){};
	virtual ~Singleton(){}; 
	Singleton<T>& operator=(const Singleton<T>& rhs);
	Singleton(const Singleton<T>& rhs);
};  


template <class T> T* Singleton<T>::ms_instance = 0;



template <class T> T* Singleton<T>::Get()  
{  
	if(!ms_instance)  
		ms_instance = new T();  
	return ms_instance;  
}

template <class T> void Singleton<T>::Free()  
{  
	if( ms_instance )  
	{  
		delete ms_instance;  
		ms_instance = 0;  
	}  
}

}
#endif //__EAM_SINGLETON_H__