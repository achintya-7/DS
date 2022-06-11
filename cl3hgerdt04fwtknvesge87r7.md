## KubeSphere 101

# What is KubeSphere?
KubeSphere is a distributed operating system for cloud-native application management, using Kubernetes as its kernel. It provides a plug-and-play architecture, allowing third-party applications to be seamlessly integrated into its ecosystem. It is also Open Source certified by CNCF. 

To get a good view and experience of UI. You can run a demo version of KubeSphere in your browser from [here](https://demo.kubesphere.io/login). 

# Why KubeSphere?
KubeSphere provides high-performance and scalable container service management for enterprises. It aims to help them accomplish digital transformation driven by cutting-edge technologies, and accelerate app iteration and business delivery to meet the ever-changing needs of enterprises.

# Key Features 
-  ### Provisioning Kubernetes  
Deploy Kubernetes anywhere easily. It also includes online and air-gapped installation, and supports for adding GPU nodes. 

- ### K8s Resource Management
    A web console for creating and managing Kubernetes resources with powerful 
    observability

- ### Multi-tenant Management
    Provide unified authentication with fine-grained roles and a three-tier authorization system, and support AD/LDAP authentication
 
- ### Multiple Storage and Networking Solutions
   Multiple Storage and Networking Solutions
Support GlusterFS, CephRBD, NFS, LocalPV solutions, and provide CSI plugins to consume storage from multiple cloud providers.

# KubeSphere Ecosystem Tools
KubeSphere integrate a large variety of tools related to Kubernetes, ranging from cloud-native apps to the underlying container runtimes. These open-source projects serve as the backend components of KubeSphere, which interact with the KubeSphere console through standard APIs, thus providing consistent user experiences to reduce complexity. <br/>
Various open-source tools like GitLab's, Ceph, Mongo-DB, etc. can be easily used by leveraging the functionality of KubeSphere 
![image.png](https://cdn.hashnode.com/res/hashnode/image/upload/v1653230271056/DwIGlsRnn.png align="left")

# Use Cases
KubeSphere is applicable in a variety of scenarios. For enterprises that deploy their business system on bare metal, their business modules are tightly coupled with each other. That means it is extremely difficult for resources to be horizontally scaled. In this connection, KubeSphere provides enterprises with containerized environments with a complete set of features for management and operation. It empowers enterprises to rise to the challenges in the middle of their digital transformation, including agile software development, automated operation and maintenance, microservices governance, traffic management, autoscaling, high availability, as well as DevOps and CI/CD.


- ### Multi-cluster Deployment
  * **High Availability ** <br/>
     Users can deploy workloads on multiple clusters by using a global VIP or DNS to 
     send requests to corresponding backend clusters.
  * **Low Latency** <br/>
     When clusters are deployed in various regions, user requests can be forwarded to 
     the nearest cluster, greatly reducing network latency.
  * **Avoid Vendor Lock-in** <br/>
     Kubernetes has become the de-facto standard in container orchestration. Against 
     this backdrop, many enterprises avoid putting all eggs in one basket as they deploy 
     clusters by using services of different cloud providers. 

- ### Full-stack Observability with Streamlined O&M
  * **Multi-dimensional Cluster Monitoring** <br/>
     The adoption of multi-cluster deployment across clouds is on the rise both among 
     individuals and enterprises.
  * **Log Query** <br/>
     A comprehensive monitoring feature is meaningless without a flexible log query 
     system. This is because users need to be able to track all the information related to 
     their resources, such as alerting messages, node scheduling status, app deployment 
     success, or network policy modification. 
  * **Customization** <br/>
     Even for resource monitoring on the same platform, the tool provided by the cloud 
     vendor may not be a panacea. In some cases, users need to create their own 
     standard of observability, such as the specific monitoring metrics and display form.

- ### Implement DevOps Practices
    DevOps represents an important set of practices or methods that engage both 
    development and Ops teams for more coordinated and efficient cooperation between 
    them. Therefore, development, testing and release can be faster, more efficient and 
    more reliable. CI/CD pipelines in KubeSphere provide enterprises with agile 
    development and automated O&M. 

- ### Service Mesh and Cloud-native Architecture
  * **Multi-cloud App Distribution** <br/>
   As mentioned above, it is not uncommon for individuals or organizations to deploy 
   apps across Kubernetes clusters, whether on-premises, public or hybrid. 

  * **Visualization** <br/>
   As users deploy microservices which will communicate among themselves 
   considerably, it will help users gain a better understanding of topological relations 
   between microservices, if the connection is highly visualized.

- ### Bare Metal Deployment
   Sometimes, the cloud is not necessarily the ideal place for the deployment of 
   resources. For example, physical, dedicated servers tend to function better when it 
   comes to cases that require considerable computing resources and high disk I/O. 
   Besides, for some specialized workloads that are difficult to migrate to a cloud 
   environment, certified hardware and complicated licensing and support agreements 
   may be required.
   

# Installation 
### Prerequisites
- Kubernetes version v1.19.x, v1.20.x, v1.21.x, or v1.22.x (experimental).
- CPU Cores > 1 && Ram > 2GB. {Only working on x86_64 CPUs for now}.
- A default StorageClass in your Kubernetes cluster, use `kubectl get sc` to verify it.

### Installation
If you meet all the previous prerequisites, you can install KubeSphere with these commands.
``` 
kubectl apply -f https://github.com/kubesphere/ks-installer/releases/download/v3.2.1/kubesphere-installer.yaml
   
kubectl apply -f https://github.com/kubesphere/ks-installer/releases/download/v3.2.1/cluster-configuration.yaml
```
You can check the logs while the installation is going on. Use this command to check the logs 
```
kubectl logs -n kubesphere-system $(kubectl get pod -n kubesphere-system -l app=ks-install -o jsonpath='{.items[0].metadata.name}') -f

```
Use this command to check if all the ports are working properly
```
kubectl get svc/ks-console -n kubesphere-system

```
go to localhost port 30880 to start using KubeSphere
the default credentials are following

> Admin : admin <p>
> Password : P@88w0rd

If you want to install KubeSphere on the cloud, you can check their docs [here](https://kubesphere.io/docs/installing-on-kubernetes/hosted-kubernetes/install-kubesphere-on-aks/)

# Conclusion

This was a basic synopsis of KubeSphere and all the services it provides. You can also check out their website to know more about [KubeSphere](https://kubesphere.io).











