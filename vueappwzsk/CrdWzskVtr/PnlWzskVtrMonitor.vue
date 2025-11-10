<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<div
				class="my-1"
				style="height:250px"
			>
				<!-- IP divApl - INSERT -->
			</div>

			<div
				class="my-1"
				style="height:250px"
			>
				<!-- IP divVpl - INSERT -->
			</div>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskVtrMonitor',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskVtrMonitor.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskVtrMonitorDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskVtrMonitor"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskVtrMonitorData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskVtrMonitorData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.StatShrWzskVtrMonitor) this.statshr = dpcheng.StatShrWzskVtrMonitor;
				if (dpcheng.TagWzskVtrMonitor) {
					Wzsk.unescapeBlock(dpcheng.TagWzskVtrMonitor);
					this.tag = dpcheng.TagWzskVtrMonitor;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskVtrMonitorData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngWzskVtrMonitorLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskVtrMonitorLive - BEGIN -->
				*/
				console.log("PnlWzskVtrMonitor.handleDpchEngWzskVtrMonitorLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskVtrMonitorLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskVtrMonitorData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskVtrMonitorLive") this.handleDpchEngWzskVtrMonitorLive(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
